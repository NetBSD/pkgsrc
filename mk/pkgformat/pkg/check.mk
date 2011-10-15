# $NetBSD: check.mk,v 1.1 2011/10/15 00:23:09 reed Exp $
#

# _pkgformat-check-vulnerable:
#	Checks for known vulnerabilities in the package if a vulnerability
#	file exists.
#
.if defined(NO_PKGTOOLS_REQD_CHECK)
_pkgformat-check-vulnerable: .PHONY
	${RUN}${DO_NADA}
.else
_pkgformat-check-vulnerable: .PHONY
	${RUN}\
	_PKGVULNDIR=`${_EXTRACT_PKGVULNDIR}`; \
	vulnfile=$$_PKGVULNDIR/pkg-vulnerabilities;		\
	if ${TEST} ! -f "$$vulnfile"; then 			\
		${PHASE_MSG} "Skipping vulnerability checks.";	\
		${WARNING_MSG} "No $$vulnfile file found.";	\
		${WARNING_MSG} "To fix run: \`${DOWNLOAD_VULN_LIST}'."; \
		exit 0;						\
	fi;							\
	${PHASE_MSG} "Checking for vulnerabilities in ${PKGNAME}"; \
	${AUDIT_PACKAGES} ${_AUDIT_PACKAGES_CMD} ${AUDIT_PACKAGES_FLAGS} ${PKGNAME} \
	|| ${FAIL_MSG} "Define ALLOW_VULNERABLE_PACKAGES in mk.conf or ${_AUDIT_CONFIG_OPTION} in ${_AUDIT_CONFIG_FILE}(5) if this package is absolutely essential."
.endif
