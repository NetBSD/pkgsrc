# $NetBSD: Makefile,v 1.2 1999/08/02 04:26:49 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.13 1999/02/10 18:13:21 motoyuki Exp $

DISTNAME=	mh-6.8.4-JP-3.02
PKGNAME=	ja-mh-6.8.4
CATEGORIES=	japanese mail
MASTER_SITES=	ftp://ports.jp.freebsd.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/ \
		ftp://komadori.planet.sci.kobe-u.ac.jp/pub/MH/ \
		ftp://ftp.chem.eng.himeji-tech.ac.jp/pub/net/mh/

MAINTAINER=	teck-pkg-ja@jp.netbsd.org

DEPENDS=	ja-less-332:../../japanese/less

CONFLICTS=	nmh-*

MANCOMPRESSED=	YES
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-batchmode \
		--libexecdir=${PREFIX}/libexec/mh \
		--enable-jmandir=${PREFIX}/man/ja_JP.EUC \
		--enable-apop=${PREFIX}/etc/pop.auth --enable-rpop

.include "../../mk/bsd.pkg.mk"
