# $NetBSD: Makefile,v 1.21 2001/02/25 04:17:41 hubertf Exp $
# FreeBSD Id: Makefile,v 1.10 1998/11/18 17:35:16 vanilla Exp
#

DISTNAME=	glade-0.5.11
CATEGORIES=	devel
MASTER_SITES=   http://glade.pn.org/ \
		${MASTER_SITE_GNOME:=stable/sources/glade/}

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://glade.pn.org/
COMMENT=	User interface builder for GTK+

DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core

GNU_CONFIGURE=	yes
USE_X11BASE=	yes

CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
CONFIGURE_ENV+=	LOCALEDIR=${LOCALEDIR}

PLIST_SUBST+=	LOCALEDIR=${LOCALEDIR}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/doc/developer.txt ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/doc/file_format.txt ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/doc/generic.txt ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/doc/manual.txt ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/doc/notes.txt ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/doc/portability.txt ${PREFIX}/share/doc/glade
	${INSTALL_DATA} ${WRKSRC}/doc/source_code.txt ${PREFIX}/share/doc/glade

.include "../../mk/bsd.prefs.mk"

# The directory in which locale files are found is:
#
#	${PREFIX}/${LOCALEDIR}/locale/<lang>/LC_MESSAGES
#
.if ${OPSYS} == "SunOS"
LOCALEDIR=		lib
.else
LOCALEDIR=		share
.endif

.include "../../mk/bsd.pkg.mk"
