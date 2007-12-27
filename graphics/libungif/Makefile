# $NetBSD: Makefile,v 1.41 2007/12/27 11:43:37 jnemeth Exp $

DISTNAME=	libungif-4.1.4
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=giflib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libungif.sourceforge.net/
COMMENT=	Tools and library routines for working with GIF images

CONFLICTS=	giflib-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ENV+=		ac_cv_lib_X11_main=no

DOCDIR=			${PREFIX}/share/doc/libungif
HTMLDIR=		${PREFIX}/share/doc/html/libungif

REPLACE_PERL+=		util/gifburst

post-patch:
	@${RM} ${WRKSRC}/doc/gif2x11.html

post-install:
	cd ${DESTDIR}${PREFIX}/lib && 					\
	for SOURCE in libungif.*; do					\
	  TARGET=`echo $$SOURCE | ${SED} -e s/libungif/libgif/`;	\
	  ${RM} -f $$TARGET; 						\
	  if [ $$SOURCE = libungif.la ]; then				\
	    ${SED} -e s/libungif/libgif/g $$SOURCE >$$TARGET;		\
	    ${CHMOD} 755 $$TARGET;					\
	  else								\
	    ${LN} -s $$SOURCE $$TARGET;					\
	  fi;								\
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING UNCOMPRESSED_GIF ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt *.png ${DESTDIR}${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
