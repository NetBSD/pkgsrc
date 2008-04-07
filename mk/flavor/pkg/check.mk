# $NetBSD: check.mk,v 1.9 2008/04/07 13:16:26 joerg Exp $
#

# _flavor-check-vulnerable:
#	Checks for known vulnerabilities in the package if a vulnerability
#	file exists.
#
_flavor-check-vulnerable: .PHONY
	${_PKG_SILENT}${_PKG_DEBUG}					\
	_PKGVULNDIR=`${AUDIT_PACKAGES} ${AUDIT_PACKAGES_FLAGS} -Q PKGVULNDIR`; \
	vulnfile=$$_PKGVULNDIR/pkg-vulnerabilities;		\
	if ${TEST} ! -f "$$vulnfile"; then 			\
		${PHASE_MSG} "Skipping vulnerability checks.";	\
		${WARNING_MSG} "No $$vulnfile file found.";	\
		${WARNING_MSG} "To fix run: \`${DOWNLOAD_VULN_LIST}'."; \
		exit 0;						\
	fi;							\
	${PHASE_MSG} "Checking for vulnerabilities in ${PKGNAME}"; \
	${AUDIT_PACKAGES} ${AUDIT_PACKAGES_FLAGS} -n ${PKGNAME};	\
	if ${TEST} "$$?" -ne 0; then				\
		${ERROR_MSG} "Define ALLOW_VULNERABLE_PACKAGES in mk.conf or IGNORE_URLS in audit-packages.conf(5) if this package is absolutely essential."; \
		${FALSE};					\
	fi
