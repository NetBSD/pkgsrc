# $NetBSD: Makefile,v 1.24 1999/03/06 23:18:51 kim Exp $
# FreeBSD Id: Makefile,v 1.2 1997/08/04 06:51:28 markm Exp
#

DISTNAME=	nmh-1.0
CATEGORIES=	mail
MASTER_SITES=   ftp://ftp.math.gatech.edu/pub/nmh/

MAINTAINER=     kim@tac.nyc.ny.us
HOMEPAGE=	http://www.math.gatech.edu/nmh/

# We choose DOT_LOCKING in our patches because ".lock" files are
# the most common locking mechanism supported by mail software.
# It also works well over NFS.

# Locks supported by `mail.local' are ".lock" and flock(2).

.include "../../mk/bsd.prefs.mk"

# Mail Transport Agent - either "smtp" or "sendmail"
NMH_MTA?=	smtp

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= \
		--libdir=${PREFIX}/libexec/nmh \
		--sysconfdir=${PREFIX}/etc/nmh \
		--enable-nmh-pop \
		--with-mts=${NMH_MTA}

.ifdef NMH_EDITOR
CONFIGURE_ARGS+= --with-editor=${NMH_EDITOR}
.endif

.ifdef NMH_PAGER
CONFIGURE_ARGS+= --with-pager=${NMH_PAGER}
.endif

.if exists(/usr/lib/libkrb.a) && (defined(MAKE_EBONES) || defined(MAKE_KERBEROS4))
CONFIGURE_ARGS+= --with-krb4=yes
.endif

DOCDIR=		share/doc/nmh

# Since we patch the autoconf files as well as their outputs, avoid attempt
# to regenerate header input files with 'autoheader' by Makefile.
post-patch:
	${TOUCH} ${WRKSRC}/stamp-h.in

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	@for f in `grep '^${DOCDIR}/' ${PKGDIR}/PLIST`; do \
	    ${INSTALL_DATA} ${WRKSRC}/`basename $$f` ${PREFIX}/${DOCDIR}; \
	done
	@${INSTALL_DATA} ${FILESDIR}/mhn.defaults ${PREFIX}/etc/nmh
	@PKG_PREFIX='${PREFIX}' sh -f ${PKGDIR}/INSTALL

.include "../../mk/bsd.pkg.mk"
