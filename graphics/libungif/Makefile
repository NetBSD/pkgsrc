# $NetBSD: Makefile,v 1.34.4.1 2005/11/05 14:03:41 salo Exp $

DISTNAME=	libungif-4.1.3
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libungif/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://libungif.sourceforge.net/
COMMENT=	Tools and library routines for working with GIF images

CONFLICTS=	giflib-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--without-x
CONFIGURE_ENV+=		ac_cv_lib_X11_main=no

DOCDIR=			${PREFIX}/share/doc/libungif
HTMLDIR=		${PREFIX}/share/doc/html/libungif

REPLACE_PERL=		util/gifburst

post-patch:
	@${RM} ${WRKSRC}/doc/gif2x11.html

post-install:
	cd ${PREFIX}/lib && 						\
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
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} COPYING UNCOMPRESSED_GIF ${DOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html *.txt *.png ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
