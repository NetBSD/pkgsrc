# $NetBSD: Makefile,v 1.11 2001/09/27 23:18:34 jlam Exp $
# FreeBSD Id: Makefile,v 1.11 1998/02/01 03:04:11 itojun Exp
#

DISTNAME=		nntpcache-2.4.0b5
CATEGORIES=		news
MASTER_SITES=		ftp://ftp.nntpcache.org/pub/nntpcache/ \
			ftp://ftp.fu-berlin.de/unix/news/nntpcache/ \
			ftp://ftp.contrib.com/pub/software/unix/news/nntpcache/ \
			ftp://ftp.eu.net/news/transport/nntpcache/ \
			ftp://ftp.belgium.eu.net/pub/news/transport/nntpcache/ \
			ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/news/nntpcache/ \
			ftp://ftp.faho.rwth-aachen.de/pub/linux/nntpcache/ \
			ftp://ftp.hway.ru/pub/news/nntpcache/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.nntpcache.org/
COMMENT=		nntp multi-server caching daemon

LICENSE=		fee-based-commercial-use

# enable ldap support?
NNTP_USE_LDAP?=		no
# enable pgp signed nocem support?
NNTP_USE_PGP?=		no

.if ${NNTP_USE_LDAP} == yes
DEPENDS+=		openldap-[0-9]*:../../databases/openldap
.endif

.if ${NNTP_USE_PGP} ==	yes
DEPENDS+=		pgp-2.*:../../security/pgp2
.endif

BUILD_DEFS+=	NNTP_USE_LDAP NNTP_USE_PGP

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=/var/spool
CONFIGURE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
USE_GMAKE=		yes

INSTALL_TARGET=		SUBDIRS="cf src filters http doc pgp contrib/newshound innreport scripts unixauth" \
			install

post-configure:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g"  \
		${FILESDIR}/nntpcached.rc > ${WRKSRC}/nntpcached.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nntpcached.sh ${PREFIX}/etc/rc.d/nntpcached
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nntpcache
	cd ${WRKSRC} && ${INSTALL_DATA} README INSTALL FAQ FAQ.html LICENSING \
		${PREFIX}/share/doc/nntpcache/

.include "../../mk/bsd.pkg.mk"
