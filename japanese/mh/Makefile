# $NetBSD: Makefile,v 1.12 2001/09/27 23:18:14 jlam Exp $
# FreeBSD Id: Makefile,v 1.13 1999/02/10 18:13:21 motoyuki Exp $

DISTNAME=	mh-6.8.4-JP-3.03
PKGNAME=	ja-mh6-3.03
CATEGORIES=	japanese mail
MASTER_SITES=	ftp://ports.jp.freebsd.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/ \
		ftp://komadori.planet.sci.kobe-u.ac.jp/pub/MH/ \
		ftp://ftp.chem.eng.himeji-tech.ac.jp/pub/net/mh/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
COMMENT=	Rand MH mail handling system + Japanese patches

DEPENDS=	ja-less>=332:../../japanese/less

CONFLICTS=	nmh-[0-9]* ja-mh-*_JP_*

.include "../../mk/bsd.prefs.mk"

MANCOMPRESSED=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	OBJECT_FMT=${OBJECT_FMT}
CONFIGURE_ARGS= --enable-batchmode \
		--libexecdir=${PREFIX}/libexec/mh \
		--enable-jmandir=${PREFIX}/man/ja_JP.EUC \
		--enable-apop=${PREFIX}/etc/pop.auth --enable-rpop

post-install:
	${LN} -sf libmh.so.3.2 ${PREFIX}/lib/libmh.so.3

.include "../../mk/bsd.pkg.mk"
