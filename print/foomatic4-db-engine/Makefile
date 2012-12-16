# $NetBSD: Makefile,v 1.12 2012/12/16 01:52:31 obache Exp $
#

DISTNAME=	foomatic-db-engine-4.0.8
PKGREVISION=	3
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
CONFIGURE_ENV+=	PERL_INSTALLDIRS=vendor
USE_TOOLS+=	perl gmake
PERL5_PACKLIST=	auto/Foomatic/.packlist

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
