# $NetBSD: check.mk,v 1.7 2008/03/15 16:12:27 joerg Exp $
#

# _flavor-check-vulnerable:
#	Checks for known vulnerabilities in the package without needing
#	audit-packages to be installed.
#
#	XXX: This should really be invoking audit-packages directly.
#	Having separately maintained piece of code that inspects the
#	vulnerabilities database is poor.
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
