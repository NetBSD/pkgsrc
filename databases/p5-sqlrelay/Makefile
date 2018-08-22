# $NetBSD: Makefile,v 1.20 2018/08/22 09:43:22 wiz Exp $

PKGNAME=		p5-${DISTNAME}
PKGREVISION=		7
COMMENT=		Perl module for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

LICENSE=		artistic

USE_TOOLS+=		perl

CONFIGURE_ARGS+=	--with-perl-site-arch=${PERL5_INSTALLVENDORARCH}
CONFIGURE_ARGS+=	--with-perl-site-lib=${PERL5_INSTALLVENDORLIB}
CONFIGURE_ARGS+=	--with-perl-install-man3-dir=${PERL5_INSTALLVENDORMAN3DIR}

BUILD_DIRS=		src/api/perl

PERL5_PACKLIST=		auto/DBD/SQLRelay/.packlist
PERL5_PACKLIST+=	auto/SQLRelay/Cursor/.packlist
PERL5_PACKLIST+=	auto/SQLRelay/Connection/.packlist

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/perl5/packlist.mk"
.include "../../lang/perl5/vars.mk"
.include "../../mk/bsd.pkg.mk"
