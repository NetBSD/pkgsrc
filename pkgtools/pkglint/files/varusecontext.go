package main

// VarUseContext defines the context in which a variable is defined
// or used. Whether that is allowed depends on:
//
// * The variable’s data type, as defined in vardefs.go.
// * Whether the variable is accessed at loading time (when the
//   Makefiles are parsed) or at run time (when the shell commands are
//   run). Especially at load time, there are several points of time
//   (e.g. the bsd.pkg.mk file is loaded at the very end, therefore
//   the variables that are defined there cannot be used at load time.)
// * When used on the right-hand side of an assigment, the variable can
//   represent a list of words, a single word or even only part of a
//   word. This distinction decides upon the correct use of the :Q
//   operator.
// * When used in shell commands, the variable can appear inside single
//   quotes, double quotes, backticks or some combination thereof. This
//   also influences whether the variable is correctly used.
// * When used in preprocessing statements like .if or .for, the other
//   operands of that statement should fit to the variable and are
//   checked against the variable type. For example, comparing OPSYS to
//   x86_64 doesn’t make sense.

type VarUseContext struct {
	time      vucTime
	vartype   *Vartype
	shellword vucShellword
	extent    vucExtent
}

type vucTime int

const (
	VUC_TIME_UNKNOWN vucTime = iota
	VUC_TIME_LOAD            // During loading, not all variables are available yet.
	VUC_TIME_RUN             // All files have been read, especially bsd.pkg.mk.
)

type vucShellword int

const (
	VUC_SHW_UNKNOWN vucShellword = iota
	VUC_SHW_PLAIN                // Example: echo LOCALBASE=${LOCALBASE}
	VUC_SHW_DQUOT                // Example: echo "The version is ${PKGVERSION}."
	VUC_SHW_SQUOT                // Example: echo 'The version is ${PKGVERSION}.'
	VUC_SHW_BACKT                // Example: echo \`sed 1q ${WRKSRC}/README\`
	VUC_SHW_FOR                  // Example: for f in ${EXAMPLE_FILES}
)

type vucExtent int

const (
	VUC_EXTENT_UNKNOWN vucExtent = iota
	VUC_EXT_WORD                 // Example: echo ${LOCALBASE}
	VUC_EXT_WORDPART             // Example: echo LOCALBASE=${LOCALBASE}
)

func (vuc *VarUseContext) String() string {
	typename := "no-type"
	if vuc.vartype != nil {
		typename = vuc.vartype.String()
	}
	return sprintf("(%s %s %s %s)",
		[]string{"unknown", "load-time", "run-time"}[vuc.time],
		typename,
		[]string{"unknown", "plain", "dquot", "squot", "backt", "for"}[vuc.shellword],
		[]string{"unknown", "word", "word-part"}[vuc.extent])
}
