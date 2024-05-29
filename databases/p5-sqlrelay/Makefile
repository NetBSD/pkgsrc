# $NetBSD: Makefile,v 1.46 2024/05/29 16:31:45 adam Exp $

PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
COMMENT=	Perl module for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

LICENSE=	artistic

USE_TOOLS+=	gmake perl

CONFIGURE_ARGS+=	--with-perl-install-man3-dir=${PERL5_INSTALLVENDORMAN3DIR}
CONFIGURE_ARGS+=	--with-perl-prefix=${BUILDLINK_PREFIX.perl}
CONFIGURE_ARGS+=	--with-perl-site-arch=${PERL5_INSTALLVENDORARCH}
CONFIGURE_ARGS+=	--with-perl-site-lib=${PERL5_INSTALLVENDORLIB}

LDFLAGS+=	-L${PREFIX}/${PERL5_SUB_INSTALLARCHLIB}/CORE

BUILD_DIRS=		src/api/perl

PERL5_PACKLIST=		auto/DBD/SQLRelay/.packlist
PERL5_PACKLIST+=	auto/SQLRelay/Cursor/.packlist
PERL5_PACKLIST+=	auto/SQLRelay/Connection/.packlist

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/perl5/packlist.mk"
.include "../../lang/perl5/vars.mk"
.include "../../mk/bsd.pkg.mk"
