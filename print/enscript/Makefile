# $NetBSD: Makefile,v 1.25 2004/04/19 00:04:54 wiz Exp $
# FreeBSD Id: Makefile,v 1.4 1997/11/27 08:10:30 tg Exp
#

DISTNAME=		enscript-1.6.1
PKGREVISION=		2
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=enscript/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ngs.fi/mtr/genscript/
COMMENT=		ASCII-to-PostScript filter

DEPENDS+=		papersize-[0-9]*:../../print/papersize

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"

EGDIR=			${PREFIX}/share/examples/enscript
CONF_FILES=		${EGDIR}/enscript.cfg ${PKG_SYSCONFDIR}/enscript.cfg

.include "../../mk/bsd.prefs.mk"
.if defined(PAPERSIZE)
CONFIGURE_ARGS+=--with-media="${PAPERSIZE}"
.endif

.include "../../mk/bsd.pkg.mk"
