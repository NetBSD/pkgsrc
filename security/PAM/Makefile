# $NetBSD: Makefile,v 1.1.1.1 2000/10/21 18:41:54 rh Exp $
#

DISTNAME=	Linux-${PKGNAME}
PKGNAME=	PAM-0.72
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.kernel.org/pub/linux/libs/pam/pre/library/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.kernel.org/pub/linux/libs/pam/

DEPENDS+=	libcrack-*:../../security/libcrack

USE_GMAKE=	YES

MAKE_ENV+=	LOWER_OPSYS="${LOWER_OPSYS}"
MAKE_ENV+=	MACHINE_GNU_ARCH="${MACHINE_GNU_ARCH}"
MAKE_ENV+=	MKDIR="${MKDIR}"
MAKE_ENV+=	ARPRG="${AR}"
MAKE_ENV+=	RANLIB="${RANLIB}"
MAKE_ENV+=	BSD_INSTALL="${INSTALL}"
MAKE_ENV+=	CONFIGED="${PREFIX}/etc"
MAKE_ENV+=	CONFD="${PREFIX}/etc"

do-configure:
	cd ${WRKSRC} && ${TOUCH} .quiet_install &&			\
	for i in `${FIND} . -type f` ; do				\
		if ${GREP} -q '\/etc\/' $$i ; then			\
			${CP} $$i $$i.old &&				\
			${SED} < $$i.old > $$i				\
			    -e 's:/etc/security:${PREFIX}/etc/pam:g' 	\
			    -e 's:/etc/pam:${PREFIX}/etc/pam:g' &&	\
			${RM} $$i.old ;					\
		fi ;							\
		if ${GREP} -q 'bash' $$i ; then				\
			${CP} $$i $$i.old &&				\
			${SED} < $$i.old > $$i				\
			    -e 's:bash:sh:g' &&				\
			${RM} $$i.old ;					\
		fi ;							\
	done

post-install:
	for doc in ${WRKSRC}/doc/man/*.3 ; do				\
		${INSTALL_MAN} $$doc ${PREFIX}/man/man3 ;		\
	done
	for doc in ${WRKSRC}/doc/man/*.8 ; do				\
		${INSTALL_MAN} $$doc ${PREFIX}/man/man8 ;		\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/PAM/modules
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/PAM/sgml
	for doc in ${WRKSRC}/doc/modules/* ; do				\
		${INSTALL_DATA} $$doc ${PREFIX}/share/doc/PAM/modules ; \
	done
	${INSTALL_DATA} ${WRKSRC}/doc/figs/pam_orient.txt 		\
		${PREFIX}/share/doc/PAM
.for doc in draft-morgan-pam.raw rfc86.0.txt
	${INSTALL_DATA} ${WRKSRC}/doc/specs/${doc} ${PREFIX}/share/doc/PAM
.endfor
.for doc in appl modules source
	${INSTALL_DATA} ${WRKSRC}/doc/pam_${doc}.sgml			\
		${PREFIX}/share/doc/PAM/sgml
.endfor

.include "../../mk/bsd.pkg.mk"
