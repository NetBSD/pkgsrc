# $NetBSD: check.mk,v 1.11 2009/03/17 22:13:36 rillig Exp $
#

# _flavor-check-vulnerable:
#	Checks for known vulnerabilities in the package if a vulnerability
#	file exists.
#
_flavor-check-vulnerable: .PHONY
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
	|| ${FAIL_MSG} "Define ALLOW_VULNERABLE_PACKAGES in mk.conf or IGNORE_URLS in audit-packages.conf(5) if this package is absolutely essential."
