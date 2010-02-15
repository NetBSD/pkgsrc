# $NetBSD: Makefile,v 1.15 2010/02/15 13:38:20 joerg Exp $
# FreeBSD Id: Makefile,v 1.20 1997/08/05 06:56:41 tg Exp
#

DISTNAME=	tetex-texmfsrc-3.0
PKGNAME=	${DISTNAME:S/tetex/teTeX/}
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/3.0/distrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Sources for machine-independent part of teTeX

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	teTeX-texmf>=3.0nb3:../../print/teTeX3-texmf

CONFLICTS+=	teTeX-sharesrc-[0-9]*

BROKEN=		Conflicts with dependency (tex-koma-script).

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	teTeX
NO_CONFIGURE=	yes
NO_BUILD=	yes

CHECK_INTERPRETER_SKIP+=	share/texmf-dist/source/*

INSTALLATION_DIRS=	share/texmf-dist

.include "../../mk/bsd.prefs.mk"

do-install:
	extract_file=${_DISTDIR:Q}/${DISTFILES:Q};			\
	cd ${DESTDIR}${PREFIX}/share/texmf-dist; ${EXTRACT_CMD}

.include "../../mk/bsd.pkg.mk"
