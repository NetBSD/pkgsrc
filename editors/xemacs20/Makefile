# $NetBSD: Makefile,v 1.27 1998/07/04 05:11:12 mycroft Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/09/03 19:27:57 gj Exp
#

DISTNAME=	xemacs-20.3
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.xemacs.org/pub/xemacs-20.3/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs-20.3/ \
		ftp://ftp.usyd.edu.au/pub/Xemacs/xemacs-20.3/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/xemacs-20.3/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/xemacs-20.3/ \
		ftp://SunSITE.sut.ac.jp/pub/archives/xemacs/xemacs-20.3/ \
		ftp://ftp.miranova.com/pub/xemacs/ \
		ftp://ftp.gw.com/mirrors/pub/unix/xemacs/xemacs-20.3/
DISTFILES=	xemacs-20.3.tar.gz xemacs-20.3-info.tar.gz

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "FreeBSD")
MAINTAINER=	me@FreeBSD.org
WITH_SOUND=	--with-sound=native
.elif (${OPSYS} == "NetBSD")
MAINTAINER=	agc@netbsd.org
WITH_SOUND=
.endif

DEPENDS+=	xpm-3.4j:../../graphics/xpm
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	Xaw3d-1.3:../../x11/Xaw3d
DEPENDS+=	png-0.96:../../graphics/png

HAS_CONFIGURE=	yes

WITH_DIALOGS=	--with-dialogs=athena3d

.if defined(USE_MULE)
WITH_MULE=	--with-mule
DISTFILES+=	xemacs-20.3-mule.tar.gz
.endif

CONFIGURE_ARGS+=${MACHINE_GNU_ARCH}--netbsd --prefix=${PREFIX} \
		--site-includes=${PREFIX}/include \
		${WITH_SOUND} \
		--site-libraries=${PREFIX}/lib \
		--sitelispdir="${PREFIX}/lib/xemacs/site-lisp ${PREFIX}/share/xemacs/site-lisp" \
		${WITH_MULE} ${WITH_DIALOGS}

MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}" INSTALL_SCRIPT="${INSTALL_SCRIPT}"

PLIST_SRC=	${WRKDIR}/PLIST.tmp

pre-configure:
	@echo "To compile in the MULE features, set the environment variable USE_MULE"

pre-install:
	${RM} -f ${WRKSRC}/etc/ctags.1.orig
	@(if [ "X${MANZ}" != X"" ]; then \
		GZSUFFIX=.gz; \
	fi; \
	${SED} -e 's|@.GZ@|'$$GZSUFFIX'|g' ${PKGDIR}/PLIST > ${PLIST_SRC})

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/${DISTNAME}
.for file in xemacs-b2m xemacs-ctags xemacs-etags gnuclient xemacs-20.3
	strip ${PREFIX}/bin/${file}
.endfor
	@if [ "X${MANZ}" != X"" ]; then \
		${WRKSRC}/lib-src/gzip-el.sh ${PREFIX}/lib/xemacs-20.3/lisp; \
	fi

.include "../../mk/bsd.pkg.mk"
