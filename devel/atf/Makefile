# $NetBSD: Makefile,v 1.19 2012/02/26 17:25:06 jmmv Exp $
#

DISTNAME=	atf-0.15
CATEGORIES=	devel
MASTER_SITES=	http://kyua.googlecode.com/files/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://code.google.com/p/kyua/wiki/ATF
COMMENT=	Automated testing framework
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		yes

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	ATF_CONFSUBDIR=
CONFIGURE_ARGS+=	ATF_SHELL=${SH:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKGCONFIG_OVERRIDE=	data/atf-c.pc.in
PKGCONFIG_OVERRIDE+=	data/atf-c++.pc.in
PKGCONFIG_OVERRIDE+=	data/atf-sh.pc.in

PKG_SYSCONFSUBDIR=	atf

XML_ENTRIES=	public "-//NetBSD//DTD ATF Tests Results 0.1//EN" \
		${PREFIX}/share/xml/atf/tests-results.dtd

.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
