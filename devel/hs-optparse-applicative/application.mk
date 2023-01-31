# $NetBSD: application.mk,v 1.3 2023/01/31 17:13:17 pho Exp $
#
# Generate shell completion scripts automatically.
#
# This mk fragment should be included in packages that install executables
# which parse command-line arguments using optparse-applicative. If the
# package installs a library too, and the library depends on
# optparse-applicative, the package should include both "application.mk"
# and "buildlink3.mk" so that pkgtools/createbuildlink works correctly.
#
# Package-settable variables:
#
# OPTPARSE_APPLICATIVE_EXECUTABLES
#	A list of names of executables supporting automatic completor
#	generation. These executables are assumed to be installed in
#	${PREFIX}/bin.
#
#	Default value: ${PKGBASE}
#
# Keywords: haskell optparse-applicative
#

OPTPARSE_APPLICATIVE_EXECUTABLES?=	${PKGBASE}

.include "../../devel/hs-optparse-applicative/buildlink3.mk"

# Declarations for ../../mk/misc/show.mk
_VARGROUPS+=					optparse-applicative
_PKG_VARS.optparse-applicative=			\
	OPTPARSE_APPLICATIVE_EXECUTABLES
_DEF_VARS.optparse-applicative=			\
	PRINT_PLIST_AWK				\
	GENERATE_PLIST				\
	OA.shell-types				\
	OA.generate-cmds
_USE_VARS.optparse-applicative=			\
	DESTDIR					\
	PKGBASE					\
	PREFIX					\
	WRKSRC
_IGN_VARS.optparse-applicative=			\
	OA.script.bash				\
	OA.script.fish				\
	OA.script.zsh
_LISTED_VARS.optparse-applicative=		\
	PRINT_PLIST_AWK				\
	GENERATE_PLIST				\
	OA.generate-cmds
_SORTED_VARS.optparse-applicative=		\
	OPTPARSE_APPLICATIVE_EXECUTABLES	\
	OA.shell-types

# A list of shell types currently supported by optparse-applicative.
OA.shell-types=	bash fish zsh

# The paths to completion script for each shell. "@exec@" will be
# substituted later.
OA.script.bash=	share/bash-completion/completions/@exec@
OA.script.fish=	share/fish/completions/@exec@.fish
OA.script.zsh=	share/zsh/site-functions/_@exec@

# Completion scripts should be excluded from PLIST files because the exact
# set of installed scripts can vary depending on the version of
# optparse-applicative. Note that we can't loop on
# ${OPTPARSE_APPLICATIVE_EXECUTABLES} with ".for" because ${PKGBASE} is not
# yet defined.
PRINT_PLIST_AWK+=					\
	${OPTPARSE_APPLICATIVE_EXECUTABLES:@.exec.@	\
		${OA.shell-types:@.shell.@		\
			/^${OA.script.${.shell.}:S/@exec@/${.exec.}/:S,/,\\/,g}$$/ \
				{ next }		\
		@}					\
	@}

# Automatically insert completion scripts to PLIST.
GENERATE_PLIST+=	\
	${OPTPARSE_APPLICATIVE_EXECUTABLES:@.exec.@	\
		${OA.shell-types:@.shell.@		\
			${ECHO} ${OA.script.${.shell.}:S/@exec@/${.exec.}/:Q}; \
		@}					\
	@}

# The post-install hook to generate completion scripts. We need to run the
# executables we just built in order to generate scripts. However, unlike
# cabal-install, the plain Cabal doesn't provide a convenient way to do
# it. So we have to resort to something fragile.
#
# Shared libraries are usually stored in ${WRKSRC}/dist/build. However, if
# the package has internal libraries, each library will have a separate
# subdirectory. This means we need to include any subdirectories in
# ${WRKSRC}/dist/build in LD_LIBRARY_PATH.
OA.generate-cmds=	\
	${OPTPARSE_APPLICATIVE_EXECUTABLES:@.exec.@	\
		${STEP_MSG} "Generating shell completion scripts for ${.exec.}"; \
		${OA.shell-types:@.shell.@		\
			${INSTALL_DATA_DIR} ${DESTDIR:Q}${PREFIX:Q}/${OA.script.${.shell.}:S/@exec@/${.exec.}/:H:Q}; \
			libpath=${WRKSRC:Q}/dist/build; \
			for ent in ${WRKSRC:Q}/dist/build/*; do \
				if ${TEST} -d "$$ent"; then \
					libpath="$${libpath}:$$ent"; \
				fi; \
			done; \
			${PKGSRC_SETENV} \
				LD_LIBRARY_PATH="$$libpath" \
				DYLD_LIBRARY_PATH="$$libpath" \
				${WRKSRC:Q}/dist/build/${.exec.:Q}/${.exec.:Q} \
				--${.shell.:Q}-completion-script \
				${PREFIX:Q}/bin/${.exec.:Q} \
				> ${DESTDIR:Q}${PREFIX:Q}/${OA.script.${.shell.}:S/@exec@/${.exec.}/:Q}; \
		@}					\
	@}
.PHONY: generate-optparse-applicative-shell-completion-scripts
post-install: generate-optparse-applicative-shell-completion-scripts
generate-optparse-applicative-shell-completion-scripts:
	${RUN}${OA.generate-cmds}
