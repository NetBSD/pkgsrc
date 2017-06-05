# $NetBSD: Makefile,v 1.15 2017/06/05 14:22:32 ryoon Exp $

PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
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
