# $NetBSD: Makefile,v 1.6 1999/11/01 04:03:09 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.13 1999/02/10 18:13:21 motoyuki Exp $

DISTNAME=	mh-6.8.4-JP-3.03
PKGNAME=	ja-mh-6.8.4_JP_3.03
CATEGORIES=	japanese mail
MASTER_SITES=	ftp://ports.jp.freebsd.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/ \
		ftp://komadori.planet.sci.kobe-u.ac.jp/pub/MH/ \
		ftp://ftp.chem.eng.himeji-tech.ac.jp/pub/net/mh/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org

DEPENDS=	ja-less-332:../../japanese/less

CONFLICTS=	nmh-*

.include "../../mk/bsd.prefs.mk"

MANCOMPRESSED=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	OBJECT_FMT=${OBJECT_FMT}
CONFIGURE_ARGS= --enable-batchmode \
		--libexecdir=${PREFIX}/libexec/mh \
		--enable-jmandir=${PREFIX}/man/ja_JP.EUC \
		--enable-apop=${PREFIX}/etc/pop.auth --enable-rpop

.include "../../mk/bsd.pkg.mk"
