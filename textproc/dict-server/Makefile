# $NetBSD: Makefile,v 1.10 2004/03/28 21:43:26 jmmv Exp $

DISTNAME=       dictd-1.8.0
PKGNAME=	dict-server-1.8.0
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.dict.org/pub/dict/
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/dict}

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.dict.org/
COMMENT=	Dictionary Service Protocol server

USE_BUILDLINK2=	# defined
USE_GNU_TOOLS+=	make
USE_PKGINSTALL=	yes
GNU_CONFIGURE=	# defined
CONFIGURE_ARGS+=--with-etcdir=${PKG_SYSCONFDIR}

ALL_TARGET=	dictd dictzip
INSTALL_TARGET=	install.dictd install.dictzip install.dictfmt

EGDIR=		${PREFIX}/share/examples/dict-server
CONF_FILES=	${EGDIR}/dictd.conf \
		${PKG_SYSCONFDIR}/dictd.conf

# A symbol T_USER is defined in trap.h so...
post-patch:
	${GREP} -lr T_USER ${WRKSRC} | \
	while read f; do \
		${MV} $$f $${f}.orig; \
		${SED} \
		    -e 's/T_USER/T_XUSER/g' \
		    -e 's/DICT_XUSER/DICT_USER/g' \
		    $${f}.orig >$$f; \
	done

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${SED} "s#/usr/lib/dict#${PREFIX}/share/dictd#" \
		${WRKSRC}/dictd.conf >${EGDIR}/dictd.conf
	${INSTALL_DATA_DIR} ${PREFIX}/share/dictd

.include "../../devel/libtool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
