# $NetBSD: Makefile,v 1.10 2003/05/05 17:29:09 grant Exp $
#

DISTNAME=       jde-2.3.2
WRKSRC=         ${WRKDIR}/${DISTNAME}/lisp
CATEGORIES=     devel editors
MASTER_SITES=	${MASTER_SITE_LOCAL}
# The "real" site has silly naming conventions:
#MASTER_SITES=   http://jdee.sunsite.dk/

MAINTAINER=     cjones@netbsd.org
HOMEPAGE=       http://jdee.sunsite.dk/
COMMENT=        Full-featured Java editing mode for emacs

DEPENDS+=       speedbar>=0.14rc2:../../editors/speedbar
DEPENDS+=       eieio>=0.17:../../lang/eieio
DEPENDS+=       semantic>=1.4rc13:../../devel/semantic
DEPENDS+=       elib>=1.0:../../devel/elib

.include "../../mk/emacs.mk"

# XEmacs has its own JDE package
EMACS_VERSIONS_ACCEPTED=emacs21		# XXX Won't compile with emacs20...

BUILD_ENV+=     EMACS=${EMACS}
MAKE_ENV+=	EMACS_LISPPREFIX=${EMACS_LISPPREFIX}

NO_CONFIGURE=   # set

MAKEFILE=       makefile

post-extract:
	@${RMDIR} ${WRKDIR}/${DISTNAME}/java/classes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jde
	${INSTALL_DATA_DIR} ${PREFIX}/share/jde
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/jde
	cd ${WRKDIR}/${DISTNAME}/doc &&					\
		${PAX} -s',^src.*,,' -s',.*\.nosearch.*,,'		\
			-rw * ${PREFIX}/share/doc/jde
	cd ${WRKDIR}/${DISTNAME} &&					\
		${PAX} -s',^java/classes.*,,' -s',^java/src.*,,'	\
			-s',.*\.nosearch.*,,' -rw java ${PREFIX}/share/jde
	cd ${WRKDIR}/${DISTNAME} &&					\
		${PAX} -rw lisp ${EMACS_LISPPREFIX}/jde

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
