# $NetBSD: check.mk,v 1.2 2020/05/28 16:22:58 maya Exp $
#

# _pkgformat-check-vulnerable:
#	Checks for known vulnerabilities in the package if a vulnerability
#	file exists.
#

ALLOW_VULNERABLE_PACKAGES?=	yes

.if defined(NO_PKGTOOLS_REQD_CHECK)
_pkgformat-check-vulnerable: .PHONY
	${RUN}${DO_NADA}
.else

_VULNFILE:=	${_EXTRACT_PKGVULNDIR:sh}/pkg-vulnerabilities
_pkgformat-check-vulnerable: .PHONY
.  if exists(${_VULNFILE})
	@${PHASE_MSG} "Checking for vulnerabilities in ${PKGNAME}"
.    if !empty(ALLOW_VULNERABLE_PACKAGES:tl:Mno)
	@${AUDIT_PACKAGES} ${_AUDIT_PACKAGES_CMD} ${AUDIT_PACKAGES_FLAGS} ${PKGNAME} \
	|| ${FAIL_MSG} "Define ALLOW_VULNERABLE_PACKAGES in mk.conf or ${_AUDIT_CONFIG_OPTION} in ${_AUDIT_CONFIG_FILE}(5) if this package is absolutely essential."
.    else
	@${AUDIT_PACKAGES} ${_AUDIT_PACKAGES_CMD} ${AUDIT_PACKAGES_FLAGS} ${PKGNAME} || ${TRUE}
.    endif
.  else
	@${PHASE_MSG} "Skipping vulnerability checks."
	@${WARNING_MSG} "No ${_VULNFILE} file found."
	@${WARNING_MSG} "To fix run: \`${DOWNLOAD_VULN_LIST}'."
.  endif

.endif
