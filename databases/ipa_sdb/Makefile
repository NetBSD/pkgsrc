# $NetBSD: Makefile,v 1.6 2012/07/11 15:42:39 wiz Exp $

DISTNAME=	ipa_sdb-1.1.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ipa-system/modules/ipa_sdb/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
HOMEPAGE=	http://ipa-system.sourceforge.net/modules/ipa_sdb/
COMMENT=	IPA simple database module
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_LIBTOOL=	yes

SHLIBTOOL_OVERRIDE=	# empty

CONFIGURE_ARGS+=	--with-mandir-ru=ru

.include "options.mk"

.include "../../sysutils/ipa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
