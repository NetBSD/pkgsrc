# $NetBSD: Makefile,v 1.7 2011/08/14 14:21:29 obache Exp $
#

DISTNAME=	foomatic-db-engine-4.0.6
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/foomatic/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linuxfoundation.org/collaborate/workgroups/openprinting/database/foomatic
COMMENT=	Foomatic's database engine

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ENV+=	PRINTF=/usr/bin/printf
CONFIGURE_ENV+=	LIBDIR=${LOCALBASE}/share/foomatic
CONFIGURE_ENV+=	FOOMATIC_RIP=${LOCALBASE}/bin/foomatic-rip
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}
CONFIGURE_ENV+=	CUPS_ETC=${PKG_SYSCONFBASE}/cups
USE_TOOLS+=	perl gmake
PERL5_PACKLIST=	auto/Foomatic/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_CONFIGURE=	no
PERL5_CONFIGURE_DIRS=	lib

# XXX generated but needs to be present before perl5-configure
post-extract:
	${TOUCH} ${WRKSRC}/lib/Foomatic/Defaults.pm

post-configure: perl5-configure

.include "../../lang/perl5/module.mk"
.include "../../textproc/libxml2/buildlink3.mk"
# XXX wget should work too
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
