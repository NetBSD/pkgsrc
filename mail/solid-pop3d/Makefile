# $NetBSD: Makefile,v 1.7 2012/10/08 12:19:31 asau Exp $

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

INSTALLATION_DIRS+=	${EGDIR} share/doc/solid-pop3d

post-install:
	cd ${WRKSRC}/doc; for i in ${EXAMPLES}; do			\
		${INSTALL_DATA} $${i} ${DESTDIR}${EGDIR}/$${i};			\
	done
.for i in AUTHORS CONFIGFILE COPYING ChangeLog INSTALL README THANKS VIRTUALS
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/share/doc/solid-pop3d
.endfor

.include "../../mk/bsd.pkg.mk"
