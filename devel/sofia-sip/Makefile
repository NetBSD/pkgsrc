# $NetBSD: Makefile,v 1.5 2014/02/12 23:17:51 tron Exp $
#

DISTNAME=	sofia-sip-1.12.11
PKGREVISION=	2
CATEGORIES=	devel net comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sofia-sip/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://sofia-sip.sourceforge.net/
COMMENT=	Open-source SIP User-Agent library

LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	awk:run pkg-config

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c

MAKE_JOBS_SAFE=	no

SUBST_CLASSES+=	awk
SUBST_FILES.awk+=	libsofia-sip-ua/msg/msg_parser.awk
SUBST_FILES.awk+=	libsofia-sip-ua/su/tag_dll.awk
SUBST_STAGE.awk=	pre-configure
SUBST_SED.awk=		-e "s,/usr/bin/env *awk,${AWK},"
SUBST_MESSAGE.awk=	Fixing path to awk.

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
