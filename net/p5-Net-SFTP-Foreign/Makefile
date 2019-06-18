# $NetBSD: Makefile,v 1.1 2019/06/18 00:30:29 gdt Exp $

DISTNAME=	Net-SFTP-Foreign-1.90
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	angelmadames@gmail.com
HOMEPAGE=	https://github.com/salva/p5-Net-SFTP-Foreign/
COMMENT=	SSH File Transfer Protocol client
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Net/SFTP/Foreign/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
