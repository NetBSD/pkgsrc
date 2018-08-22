# $NetBSD: Makefile,v 1.8 2018/08/22 09:44:09 wiz Exp $

DISTNAME=	IPC-Cache-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~dclinton/IPC-Cache-0.02/Cache.pm
COMMENT=	Perl module that implements an object storage space
LICENSE=	gnu-gpl-v1

DEPENDS+=	p5-IPC-ShareLite>=0.06:../../devel/p5-IPC-ShareLite
#DEPENDS+=	p5-Storable>=0.607:../../devel/p5-Storable

PERL5_PACKLIST=	auto/IPC/Cache/.packlist
USE_LANGUAGES=	# none
REPLACE_PERL+=	Cache.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
