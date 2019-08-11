# $NetBSD: Makefile,v 1.5 2019/08/11 13:22:58 wiz Exp $

DISTNAME=	Net-SFTP-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

HOMEPAGE=	https://metacpan.org/release/Net-SFTP
COMMENT=	Module implementing a client for the Secure File Transfer Protocol
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Net-SSH>=2.12:../../security/p5-Net-SSH
DEPENDS+=	p5-Math-Int64>=0.54:../../math/p5-Math-Int64

PERL5_PACKLIST=	auto/Net/SFTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
