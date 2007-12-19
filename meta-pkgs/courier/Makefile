# $NetBSD: Makefile,v 1.12 2007/12/19 12:27:27 rillig Exp $

DISTNAME=	courier-${COURIER_VERSION}
PKGREVISION=	1
CATEGORIES=	meta-pkgs mail
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@pkgsrc.org
HOMEPAGE=	http://www.courier-mta.org/
COMMENT=	Meta-package for the Courier mail server suite

# COURIER_VERSION should match the variable of the same name found in
# pkgsrc/mail/courier-mta/Makefile.common.
#
COURIER_VERSION=	0.57.1

# The following packages are built from the same Courier sources and
# should match in version number:
#
#	net/couriertcpd, mail/courier-maildir, mail/courier-mta
#
DEPENDS+=	couriertcpd>=${COURIER_VERSION}:../../net/couriertcpd
DEPENDS+=	courier-maildir>=${COURIER_VERSION}:../../mail/courier-maildir
DEPENDS+=	courier-mta>=${COURIER_VERSION}nb1:../../mail/courier-mta

# The following packages must be from the same lineage as the version
# of Courier:
#
#	mail/maildrop, mail/courier-imap, mail/sqwebmail
#
DEPENDS+=	maildrop>=2.0.4nb2:../../mail/maildrop
DEPENDS+=	courier-imap>=4.2.1:../../mail/courier-imap
DEPENDS+=	sqwebmail>=5.2.0:../../mail/sqwebmail

# We tack on courier-analog because its version is somewhat tied to the
# log format of the current Courier release.
#
DEPENDS+=	courier-analog>=0.15:../../mail/courier-analog

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
