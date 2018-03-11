# $NetBSD: Makefile,v 1.23 2018/03/11 19:44:36 wiz Exp $

DISTNAME=	m17n-db-1.8.0
CATEGORIES=	misc
MASTER_SITES=	http://download.savannah.gnu.org/releases/m17n/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/m17n/
COMMENT=	The m17n database used by the m17n library
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	m17n-contrib-[0-9]*
SUPERSEDES+=	m17n-contrib-[0-9]*

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt pkg-config awk:run
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c

PKGCONFIG_OVERRIDE+=	m17n-db.pc.in

REPLACE_AWK=		tbl2mim.awk

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
GLIBC=			glibc-2.3.6
DISTFILES=		${DEFAULT_DISTFILES} ${GLIBC}.tar.gz
SITES.${GLIBC}.tar.gz=	${MASTER_SITE_GNU:=glibc/}
CONFIGURE_ARGS+=	--with-charmaps=${WRKDIR}/${GLIBC}/localedata/charmaps
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
