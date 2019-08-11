# $NetBSD: Makefile,v 1.10 2019/08/11 13:19:39 wiz Exp $

DISTNAME=	IPC-Cache-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/release/DCLINTON/IPC-Cache-0.02/Cache.pm
COMMENT=	Perl module that implements an object storage space
LICENSE=	gnu-gpl-v1

DEPENDS+=	p5-IPC-ShareLite>=0.06:../../devel/p5-IPC-ShareLite
#DEPENDS+=	p5-Storable>=0.607:../../devel/p5-Storable

PERL5_PACKLIST=	auto/IPC/Cache/.packlist
USE_LANGUAGES=	# none
REPLACE_PERL+=	Cache.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
