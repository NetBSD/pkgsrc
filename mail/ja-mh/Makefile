# $NetBSD: Makefile,v 1.8 2005/12/05 20:50:32 rillig Exp $

DISTNAME=	mh-6.8.4-JP-3.05
PKGNAME=	ja-mh6-3.05
PKGREVISION=	1
CATEGORIES=	japanese mail
MASTER_SITES=	ftp://ftp.chem.eng.himeji-tech.ac.jp/pub/net/mh/

PATCH_SITES=	ftp://ftp.chem.eng.himeji-tech.ac.jp/pub/net/mh/mh-6.8.4-JP-3.05-patch/
PATCHFILES=	mh-6.8.4-JP-3.05-20030114.patch.gz \
		mh-6.8.4-JP-3.05-20030326.patch.gz \
		mh-6.8.4-JP-3.05-20031023.patch.gz \
		mh-6.8.4-JP-3.05-20031106.patch.gz

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.chem.eng.himeji-tech.ac.jp/mh-plus/
COMMENT=	Rand MH mail handling system + Japanese patches

DEPENDS+=	ja-less>=332:../../misc/ja-less

CONFLICTS=	nmh-[0-9]* ja-mh-*_JP_*

.include "../../mk/bsd.prefs.mk"

MANCOMPRESSED=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-batchmode
CONFIGURE_ARGS+=	--libexecdir=${PREFIX:Q}/libexec/mh
CONFIGURE_ARGS+=	--enable-jmandir=${PREFIX:Q}/${PKGMANDIR:Q}/ja_JP.EUC
CONFIGURE_ARGS+=	--enable-apop=${PREFIX:Q}/etc/pop.auth
CONFIGURE_ARGS+=	--enable-rpop

post-install:
	${LN} -sf libmh.so.3.2 ${PREFIX}/lib/libmh.so.3

.include "../../mk/bsd.pkg.mk"
