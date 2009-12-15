# $NetBSD: Makefile,v 1.26 2009/12/15 22:13:40 joerg Exp $

DISTNAME=	dictd-1.9.15
PKGNAME=	dict-server-1.9.15
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dict/} \
		ftp://ftp.dict.org/pub/dict/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dict.org/
COMMENT=	Dictionary Service Protocol server

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake lex yacc
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cflags=${CFLAGS:M*:Q}
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR:Q}

BUILD_TARGET=	dictd dictzip
INSTALL_TARGET=	install.dictd install.dictzip install.dictfmt
INSTALLATION_DIRS=	${EGDIR} share/dictd

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
	${SED} "s#/usr/lib/dict#${PREFIX}/share/dictd#" \
		${WRKSRC}/dictd.conf >${DESTDIR}${EGDIR}/dictd.conf

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
