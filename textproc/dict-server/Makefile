# $NetBSD: Makefile,v 1.9 2004/01/24 15:13:19 grant Exp $

DISTNAME=       dictd-1.8.0
PKGNAME=	dict-server-1.8.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.dict.org/pub/dict/
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/dict}

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.dict.org/
COMMENT=	Dictionary Service Protocol server

USE_BUILDLINK2=	# defined
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	# defined
CONFIGURE_ARGS+=--with-etcdir=${PREFIX}/etc

ALL_TARGET=	dictd dictzip
INSTALL_TARGET=	install.dictd install.dictzip install.dictfmt

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
	${SED} "s#/usr/lib/dict#${PREFIX}/share/dictd#" \
		${WRKSRC}/dictd.conf >${PREFIX}/etc/dictd.conf
	${INSTALL_DATA_DIR} ${PREFIX}/share/dictd

.include "../../devel/libtool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
