# $NetBSD: Makefile,v 1.19 2005/12/05 23:55:20 rillig Exp $

DISTNAME=	dictd-1.9.15
PKGNAME=	dict-server-1.9.15
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dict/} \
		ftp://ftp.dict.org/pub/dict/

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.dict.org/
COMMENT=	Dictionary Service Protocol server

USE_TOOLS+=		gmake
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cflags=${CFLAGS:M*:Q}
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR:Q}

BUILD_TARGET=	dictd dictzip
INSTALL_TARGET=	install.dictd install.dictzip install.dictfmt

EGDIR=		${PREFIX}/share/examples/dict-server
CONF_FILES=	${EGDIR}/dictd.conf \
		${PKG_SYSCONFDIR}/dictd.conf

# A symbol T_USER is defined in trap.h so...
post-patch:
	${GREP} -lr T_USER ${WRKSRC} | \
	while read f; do \
		${MV} $$f $${f}.orig; \
		${SED}	-e 's/T_USER/T_XUSER/g' \
			-e 's/DICT_XUSER/DICT_USER/g' $${f}.orig >$$f; \
	done

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${SED} "s#/usr/lib/dict#${PREFIX}/share/dictd#" \
		${WRKSRC}/dictd.conf >${EGDIR}/dictd.conf
	${INSTALL_DATA_DIR} ${PREFIX}/share/dictd

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
