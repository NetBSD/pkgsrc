# $NetBSD: Makefile,v 1.20 2001/06/16 19:50:57 jlam Exp $

DISTNAME=		esound-0.2.22
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/esound/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.tux.org/~ricdude/EsounD.html
COMMENT=		the Enlightened sound daemon

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_CONFIG_WRAPPER=	YES

.include "../../audio/libaudiofile/buildlink.mk"
.include "../../devel/libgetopt/buildlink.mk"

# Fix esd-config by removing buildlink directory references.
post-build:
	@cd ${WRKSRC};							\
	${MV} -f esd-config esd-config.fixme;				\
	${SED}  -e "/^audiofile/s|-I${BUILDLINK_DIR}/|-I${LOCALBASE}/|g" \
		-e "/^audiofile/s|-L${BUILDLINK_DIR}/|-L${LOCALBASE}/|g" \
		esd-config.fixme > esd-config;				\
	${RM} -f esd-config.fixme;					\
	${CHMOD} +x esd-config

.include "../../mk/bsd.pkg.mk"
