# $NetBSD: Makefile,v 1.16 2008/10/19 19:17:42 he Exp $
#

DISTNAME=	nkf205
PKGNAME=	p5-nkf-2.05
PKGREVISION=	2
SVR4_PKGNAME=	p5nkf
CATEGORIES=	japanese converters perl5
MASTER_SITES=	http://www01.tcp-ip.or.jp/~furukawa/nkf_utf8/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://sourceforge.jp/projects/nkf/
COMMENT=	Perl library for Network Kanji code conversion Filter

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/NKF.mod
PERL5_PACKLIST=		auto/NKF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
