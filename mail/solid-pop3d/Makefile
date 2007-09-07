# $NetBSD: Makefile,v 1.5 2007/09/07 22:07:31 jlam Exp $

DISTNAME=		solid-pop3d-0.15
CATEGORIES=		mail
MASTER_SITES=		http://solidpop3d.pld.org.pl/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://solidpop3d.pld.org.pl/
COMMENT=		Flexible POP3 server

EGDIR=			${PREFIX}/share/examples/spop3d
MESSAGE_SUBST+=		EGDIR=${EGDIR}

PLIST_SRC=		# empty
EXAMPLES=		# empty

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-logextend
CONFIGURE_ARGS+=	--enable-statistics

.include "options.mk"

PLIST_SRC+=		${PKGDIR}/PLIST
EXAMPLES+=		config.example

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/doc; for i in ${EXAMPLES}; do			\
		${INSTALL_DATA} $${i} ${EGDIR}/$${i};			\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/solid-pop3d
.for i in AUTHORS CONFIGFILE COPYING ChangeLog INSTALL README THANKS VIRTUALS
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/solid-pop3d
.endfor

.include "../../mk/bsd.pkg.mk"
