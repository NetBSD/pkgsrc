# $NetBSD: Makefile,v 1.3 2007/11/11 21:46:41 jmmv Exp $
#

DISTNAME=	atf-0.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/jmmv/atf/0.3/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/~jmmv/atf/
COMMENT=	Automated testing framework

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c++
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	ATF_CONFSUBDIR=
CONFIGURE_ARGS+=	ATF_SHELL=${SH:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	atf

XML_ENTRIES=	public "-//NetBSD//DTD ATF Tests Results 0.1//EN" \
		${PREFIX}/share/xml/atf/tests-results.dtd

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
