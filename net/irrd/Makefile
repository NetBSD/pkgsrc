# $NetBSD: Makefile,v 1.28 2005/05/13 16:54:13 jlam Exp $

DISTNAME=		irrd2.2.3
PKGNAME=		irrd-2.2.3
CATEGORIES=		net
MASTER_SITES=		http://www.irrd.net/ \
			ftp://ftp.merit.edu/radb/irrd/ \
			ftp://ftp.merit.edu/radb/irrd/old_releases/
EXTRACT_SUFX=		.tgz

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.irrd.net/
COMMENT=		Internet Routing Registry Daemon

DEPENDS+=		gnupg-[0-9]*:../../security/gnupg
DEPENDS+=		wget-[0-9]*:../../net/wget

USE_PERL5=		# defined

WRKSRC=			${WRKDIR}/${DISTNAME}/src

#PTHREAD_AUTO_VARS=	yes
#PTHREAD_OPTS+=		require

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-thread
CONFIGURE_ENV+=		EGREP=${EGREP}
CONFIGURE_ENV+=		YACC=${TOOLS_YACC:Q}

BUILD_DEFS+=		USE_INET6

CPPFLAGS+=		-I${LOCALBASE}/include
CFLAGS+=		-g

IRRD_CACHER=		irrdcacher ripe2rpsl

.include "../../mk/automake.mk"

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL} && ${AUTOHEADER} && ${AUTOCONF}

post-build:
	@cd ${WRKSRC}/programs/irrdcacher ; \
	set -x ; \
	for i in ${IRRD_CACHER} ; \
	do \
	    ${MV} $$i $$i.bak ; \
	    ${SED} -e 's,/usr/bin/perl,${PERL5},' < $$i.bak > $$i ; \
	done

post-install:
	@cd ${WRKSRC}/programs/IRRd && ${MAKE} install-man
	@cd ${WRKSRC}/programs/irrdcacher ; \
	set -x ; \
	for i in ${IRRD_CACHER} ; \
	do \
	    ${INSTALL_SCRIPT} $$i ${PREFIX}/sbin ; \
	done

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == "YES"
# default
# CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

#.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
