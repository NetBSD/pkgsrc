# $NetBSD: Makefile,v 1.13 2011/11/11 09:18:31 sbd Exp $

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
HOMEPAGE=	http://media.laic.u-hyogo.ac.jp/%7Ehayashi/internet/mh-plus.html
COMMENT=	Rand MH mail handling system + Japanese patches

NOT_FOR_BULK_PLATFORM=	Linux-*-*

DEPENDS+=	ja-less>=332:../../misc/ja-less

CONFLICTS=	nmh-[0-9]* ja-mh-*_JP_*

PKG_DESTDIR_SUPPORT=	destdir

.include "../../mk/bsd.prefs.mk"

MAKE_JOBS_SAFE=	NO
MANCOMPRESSED=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-batchmode
CONFIGURE_ARGS+=	--libexecdir=${PREFIX:Q}/libexec/mh
CONFIGURE_ARGS+=	--enable-jmandir=${PREFIX:Q}/${PKGMANDIR:Q}/ja_JP.EUC
CONFIGURE_ARGS+=	--enable-apop=${PREFIX:Q}/etc/pop.auth
CONFIGURE_ARGS+=	--enable-rpop

INSTALLATION_DIRS=	bin lib

post-install:
	${LN} -sf libmh.so.3.2 ${DESTDIR}${PREFIX}/lib/libmh.so.3

.include "../../mk/bsd.pkg.mk"
