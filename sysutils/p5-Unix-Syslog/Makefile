# $NetBSD: Makefile,v 1.20 2008/07/18 14:26:24 rhaen Exp $

DISTNAME=	Unix-Syslog-1.1
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sl
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unix/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module interface to the UNIX system logger

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Unix/Syslog/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
