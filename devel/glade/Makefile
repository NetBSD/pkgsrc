# $NetBSD: Makefile,v 1.18 2000/11/09 17:59:51 mycroft Exp $
# FreeBSD Id: Makefile,v 1.10 1998/11/18 17:35:16 vanilla Exp
#

DISTNAME=	glade-0.5.11
CATEGORIES=	devel
MASTER_SITES=   http://glade.pn.org/ \
		${MASTER_SITE_GNOME:=stable/sources/glade/}

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://glade.pn.org/

DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core

GNU_CONFIGURE=	yes
USE_X11BASE=	yes

CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
CONFIGURE_ENV+=	LOCALEBASE=${LOCALEBASE}

PLIST_SUBST+=	LOCALEBASE=${LOCALEBASE}

post-install:
	${MKDIR} ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/TODO ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/developer.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/file_format.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/generic.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/manual.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/notes.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/portability.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/source_code.txt ${PREFIX}/share/doc/glade

.include "../../mk/bsd.prefs.mk"

# The directory in which locale files are found is:
#
#	${PREFIX}/${LOCALEBASE}/locale/<lang>/LC_MESSAGES
#
.if ${OPSYS} == "SunOS"
LOCALEBASE=		lib
.else
LOCALEBASE=		share
.endif

.include "../../mk/bsd.pkg.mk"
