# $NetBSD: Makefile,v 1.2 2009/06/11 22:52:56 joerg Exp $
#

.include "../../print/poppler/Makefile.common"

PKGNAME=		poppler-includes-${POPPLER_VERS}
PKGREVISION=		1

COMMENT=		Poppler Xpdf includes (unsupported)
MAINTAINER=		dillo@NetBSD.org

CONFLICTS+=		poppler-0.5.1 poppler-0.5.1nb1 poppler-0.5.1nb2

NO_BUILD=		yes
PKG_DESTDIR_SUPPORT=    user-destdir

INCDIR=${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_DATA_DIR} ${INCDIR}
	for subdir in poppler goo splash;				\
	do								\
          mf=${WRKSRC}/"$$subdir"/Makefile.am;				\
	  d=`sed -n -f ${FILESDIR}/dir.sed "$$mf"`;			\
	  ${INSTALL_DATA_DIR} ${INCDIR}/"$$d";				\
	  sed -n -f ${FILESDIR}/extract.sed "$$mf"			\
	   | { while read f;						\
	     do								\
	      ${INSTALL_DATA} ${WRKSRC}/"$$subdir/$$f" ${INCDIR}/"$$d";	\
	     done };							\
	done
	${INSTALL_DATA} ${WRKSRC}/poppler/SplashOutputDev.h ${INCDIR}/poppler

.include "../../mk/bsd.pkg.mk"
