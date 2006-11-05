# $NetBSD: Makefile,v 1.12 2006/11/05 13:11:39 rillig Exp $
#

DISTNAME=	aegis-4.22
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://aegis.sourceforge.net/

MAINTAINER=	Matthew@Aldous.com
HOMEPAGE=	http://aegis.sourceforge.net/
COMMENT=	Aegis is a transaction base software configuration management system

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-nlsdir=${_PKGLOCALEDIR:Q}
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		groff gsoelim msgfmt perl:run yacc

EGDIR=			${PREFIX}/share/examples/aegis
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

CONF_FILES+=		${EGDIR}/profile.d/aegis.csh ${PKG_SYSCONFDIR}/profile.d/aegis.csh
CONF_FILES+=		${EGDIR}/profile.d/aegis.sh ${PKG_SYSCONFDIR}/profile.d/aegis.sh

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
