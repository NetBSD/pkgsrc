# $NetBSD: Makefile,v 1.20 2001/12/03 09:30:36 abs Exp $
# FreeBSD Id: Makefile,v 1.16 1997/12/24 17:45:28 ache Exp
#

DISTNAME=	wu-ftpd-2.6.2
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.wu-ftpd.org/pub/wu-ftpd/ \
		ftp://ftp.landfield.com/wu-ftpd/wu-ftpd.org/wu-ftpd/ \
		ftp://ftp.academy.rpi.edu/pub/wu-ftpd/wu-ftpd/ \
		ftp://ftp.auscert.org.au/pub/mirrors/ftp.wu-ftpd.org/wu-ftpd/ \
		ftp://mirror.aarnet.edu.au/pub/wu-ftpd/wu-ftpd/ \
		http://mirror.aarnet.edu.au/pub/wu-ftpd/wu-ftpd/ \
		ftp://ftp.tuwien.ac.at/infosys/servers/ftp/wu-ftpd/wu-ftpd/ \
		http://gd.tuwien.ac.at/infosys/servers/ftp/wu-ftpd/wu-ftpd/ \
		ftp://ftp.crc.ca/pub/packages/ftp/servers/wuarchive-ftpd-dg/wu-ftpd/ \
		ftp://ftp.dpn.de/pub/mirrors/wu-ftpd/wu-ftpd/ \
		ftp://ftp.tu-clausthal.de/pub/mirror/wu-ftpd/wu-ftpd/ \
		ftp://ftp.freenet.de/pub/ftp.wu-ftpd.org/pub/wu-ftpd/ \
		ftp://ftp.hol.gr/pub/packages/wu-ftpd/wu-ftpd/ \
		ftp://ftp.kfki.hu/pub/infosystems/wu-ftpd/wu-ftpd/ \
		ftp://ftp.ring.gr.jp/pub/net/wu-ftpd/wu-ftpd/ \
		ftp://ftp.win.ne.jp/pub/network/wu-ftpd/wu-ftpd/ \
		ftp://ftp.bitcon.no/pub/unix/networking/wu-ftpd/wu-ftpd/ \
		ftp://ftp.sunet.se/pub/nir/ftp/servers/wuarchive-ftpd/wu-ftpd/ \
		ftp://sunsite.cnlab-switch.ch/mirror/wu-ftpd/wu-ftpd/ \
		ftp://ftp.ox.ac.uk/pub/comp/security/COAST/mirrors/ftp.vr.net/wu-ftpd/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.wu-ftpd.org/
COMMENT=	Replacement ftp server for Un*x systems

CONFLICTS=	wu-ftpd-vr-[0-9]*
CONFLICTS+=	beroftpd-[0-9]*
CONFLICTS+=	kth-krb4-[0-9]*
CONFLICTS+=	lukemftpd-[0-9]*

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--enable-quota --enable-noop --enable-skey

DIST_SUBDIR=		wu-ftpd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && make(do-configure)
CFLAGS+=	-DHAVE_SYS_MOUNT
.endif

MAKE_ENV+=	INSTALL="${INSTALL}"
MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}"

.include "../../mk/bsd.pkg.mk"
