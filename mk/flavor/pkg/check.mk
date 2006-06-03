# $NetBSD: check.mk,v 1.1 2006/06/03 23:11:42 jlam Exp $

######################################################################
### check-vulnerable (PUBLIC, pkgsrc/mk/check/check.mk)
######################################################################
### check-vulnerable checks for any vulnerabilities in the package
### without needing audit-packages to be installed.
###
### XXX This should really be invoking audit-packages directly.  Having
### XXX a separately maintained piece of code that inspects the
### XXX vulnerabilities database is poor.
###
.PHONY: check-vulnerable
check-vulnerable:
	@if [ ! -z "${PKG_SYSCONFDIR.audit-packages}" -a -f ${PKG_SYSCONFDIR.audit-packages}/audit-packages.conf ]; then \
		. ${PKG_SYSCONFDIR.audit-packages}/audit-packages.conf;	\
	elif [ ! -z "${PKG_SYSCONFDIR}" -a -f ${PKG_SYSCONFDIR}/audit-packages.conf ]; then \
		. ${PKG_SYSCONFDIR}/audit-packages.conf;		\
	fi;								\
	if [ -f ${PKGVULNDIR}/pkg-vulnerabilities ]; then		\
		${SETENV} PKGNAME=${PKGNAME}				\
			  PKGBASE=${PKGBASE}				\
		${AWK} '/^$$/ { next }				\
			/^#.*/ { next }				\
			$$1 !~ ENVIRON["PKGBASE"] && $$1 !~ /\{/ { next } \
			{ s = sprintf("${PKG_ADMIN} pmatch \"%s\" %s && ${ECHO} \"*** WARNING - %s vulnerability in %s - see %s for more information ***\"", $$1, ENVIRON["PKGNAME"], $$2, ENVIRON["PKGNAME"], $$3); system(s); }' < ${PKGVULNDIR}/pkg-vulnerabilities || ${FALSE}; \
	fi
