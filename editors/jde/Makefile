# $NetBSD: Makefile,v 1.21 2006/09/09 02:41:58 obache Exp $
#

DISTNAME=	jde-2.3.2
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel editors java
MASTER_SITES=	${MASTER_SITE_LOCAL}
# The "real" site has silly naming conventions:
#MASTER_SITES=	http://jdee.sunsite.dk/

MAINTAINER=	cjones@NetBSD.org
HOMEPAGE=	http://jdee.sunsite.dk/
COMMENT=	Full-featured Java editing mode for emacs

DEPENDS+=	${EMACS_PKGNAME_PREFIX}speedbar>=0.14rc2:../../editors/speedbar
DEPENDS+=	${EMACS_PKGNAME_PREFIX}eieio>=0.17:../../lang/eieio
DEPENDS+=	${EMACS_PKGNAME_PREFIX}semantic>=1.4rc13:../../devel/semantic
DEPENDS+=	${EMACS_PKGNAME_PREFIX}elib>=1.0:../../devel/elib

WRKSRC=		${WRKDIR}/${DISTNAME}/lisp

.include "../../mk/emacs.mk"

# XEmacs has its own JDE package
EMACS_VERSIONS_ACCEPTED=emacs21		# XXX Won't compile with emacs20...

PKG_DEFAULT_JVM=	sun-jdk14

PKGSRC_MAKE_ENV+=	EMACS=${EMACS}
MAKE_ENV+=		EMACS_LISPPREFIX=${EMACS_LISPPREFIX:Q}

NO_CONFIGURE=	yes

MAKE_FILE=	makefile

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
		${PAX} -rw -s ',.*\.orig$$,,' lisp ${EMACS_LISPPREFIX}/jde

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
