# $NetBSD: Makefile,v 1.35 1998/09/22 06:11:36 garbled Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1997/09/03 19:27:57 gj Exp
#

DISTNAME=	xemacs-20.4
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.xemacs.org/pub/xemacs/xemacs-20.4/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs-20.4/ \
		ftp://ftp.usyd.edu.au/pub/Xemacs/xemacs-20.4/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/xemacs-20.4/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/xemacs-20.4/ \
		ftp://SunSITE.sut.ac.jp/pub/archives/xemacs/xemacs-20.4/ \
		ftp://ftp.miranova.com/pub/xemacs/ \
		ftp://ftp.gw.com/mirrors/pub/unix/xemacs/xemacs-20.4/
DISTFILES=	xemacs-20.4.tar.gz xemacs-20.4-info.tar.gz

NOT_FOR_ARCHS=	alpha	#fails purespace dumping

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.xemacs.org/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	Xaw3d-1.5:../../x11/Xaw3d
DEPENDS+=	png-1.0.2:../../graphics/png
DEPENDS+=	gdbm-1.7.3:../../databases/gdbm

CONFLICTS+=	xemacs-20.3

HAS_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

WITH_DIALOGS=	--with-dialogs=athena3d
WITH_SOUND=

.if defined(USE_MULE)
WITH_MULE=	--with-mule
DISTFILES+=	xemacs-20.4-mule.tar.gz
REALPLIST=	PLIST.mule
.else
REALPLIST=	PLIST.nomule
.endif

.if defined(USE_XFACE)
WITH_XFACE=	--with-xface
DEPENDS+=	faces-1.6.1:../../mail/faces
.else
WITH_XFACE=	--with-xface=no
.endif

CONFIGURE_ARGS+=${MACHINE_GNU_ARCH}--netbsd --prefix=${PREFIX} \
		--site-includes=${PREFIX}/include \
		--infopath="${PREFIX}/info:${X11BASE}/info:/usr/local/info" \
		--site-libraries=${PREFIX}/lib \
		--sitelispdir="${PREFIX}/lib/xemacs/site-lisp \
		${PREFIX}/share/xemacs/site-lisp" -with-ncurses=no \
		${WITH_MULE} ${WITH_DIALOGS} ${WITH_XFACE} ${WITH_SOUND}

MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}" INSTALL_SCRIPT="${INSTALL_SCRIPT}"

PLIST_SRC=	${WRKDIR}/PLIST.tmp

pre-configure:
	@${ECHO} "To compile in the MULE features, set the environment variable USE_MULE."
	@${ECHO} "To compile in the support for xface, set the environment variable USE_XFACE."

pre-install:
	${RM} -f ${WRKSRC}/etc/ctags.1.orig
	@(if [ "X${MANZ}" != X"" ]; then \
		GZSUFFIX=.gz; \
	fi; \
	${SED} -e 's|@.GZ@|'$$GZSUFFIX'|g' ${PKGDIR}/${REALPLIST} \
		> ${PLIST_SRC})

post-install:
	chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/${DISTNAME}
.for file in xemacs-b2m xemacs-ctags xemacs-etags gnuclient xemacs-20.4
	strip ${PREFIX}/bin/${file}
.endfor
	@if [ "X${MANZ}" != X"" ]; then \
		${WRKSRC}/lib-src/gzip-el.sh ${PREFIX}/lib/xemacs-20.4; \
	fi

.include "../../mk/bsd.pkg.mk"
