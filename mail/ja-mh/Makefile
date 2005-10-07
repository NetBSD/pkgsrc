# $NetBSD: Makefile,v 1.7 2005/10/07 18:42:01 wiz Exp $

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

DEPENDS=	ja-less>=332:../../misc/ja-less

CONFLICTS=	nmh-[0-9]* ja-mh-*_JP_*

.include "../../mk/bsd.prefs.mk"

MANCOMPRESSED=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-batchmode \
		--libexecdir=${PREFIX}/libexec/mh \
		--enable-jmandir=${PREFIX}/${PKGMANDIR}/ja_JP.EUC \
		--enable-apop=${PREFIX}/etc/pop.auth --enable-rpop

post-install:
	${LN} -sf libmh.so.3.2 ${PREFIX}/lib/libmh.so.3

.include "../../mk/bsd.pkg.mk"
