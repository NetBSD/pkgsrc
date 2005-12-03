# $NetBSD: bsd.sites.mk,v 1.43.2.1 2005/12/03 00:11:05 salo Exp $
#
# Default MASTER_SITES

.if !defined(BSD_SITES_MK)
BSD_SITES_MK=	1

MASTER_SITE_XCONTRIB+=  \
	ftp://ftp.gwdg.de/pub/x11/x.org/contrib/ \
	ftp://sunsite.doc.ic.ac.uk/sites/ftp.x.org/contrib/ \
	ftp://sunsite.sut.ac.jp/pub/archives/X11/contrib/ \
	ftp://sunsite.icm.edu.pl/pub/X11/contrib/ \
	ftp://sunsite.cnlab-switch.ch/mirror/X11/contrib/ \
	ftp://ftp.cica.es/pub/X/contrib/ \
	ftp://ftp.unicamp.br/pub/X11/contrib/ \
	ftp://ftp.x.org/contrib/

MASTER_SITE_GNU+=       \
	ftp://ftp.gnu.org/pub/gnu/ \
	http://public.planetmirror.com.au/pub/gnu/ \
	ftp://ftp.funet.fi/pub/gnu/prep/ \
	ftp://ftp.wustl.edu/mirrors/gnu/ \
	ftp://ftp.kddlabs.co.jp/pub/gnu/gnu/ \
	ftp://ftp.dti.ad.jp/pub/GNU/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.gnu.org/gnu/ \
	ftp://ftp.informatik.hu-berlin.de/pub/gnu/ \
	ftp://ftp.rediris.es/mirror/GNU/gnu/ \
	ftp://ftp.lip6.fr/pub/gnu/ \
	ftp://ftp.tuwien.ac.at/linux/gnu/gnusrc/ \
	ftp://ftp.chg.ru/pub/gnu/

MASTER_SITE_GNUSTEP+=   \
	ftp://ftp.gnustep.org/pub/gnustep/ \
	http://public.planetmirror.com.au/pub/gnustep/gnustep/ \
	http://www.peanuts.org/peanuts/Mirrors/GNUstep/gnustep/ \
	ftp://archive.progeny.com/gnustep/ \
	http://archive.progeny.com/gnustep/ \
	ftp://ftp.easynet.nl/mirror/GNUstep/pub/gnustep/ \
	http://ftp.easynet.nl/mirror/GNUstep/pub/gnustep/

MASTER_SITE_PERL_CPAN+= \
	ftp://cpan.pair.com/modules/by-module/ \
	ftp://mirrors.cloud9.net/mirrors/CPAN/modules/by-module/ \
	http://ftp.u-paris10.fr/perl/CPAN/modules/by-module/ \
	ftp://ftp.funet.fi/pub/languages/perl/CPAN/modules/by-module/ \
	ftp://ftp.gmd.de/mirrors/CPAN/modules/by-module/ \
	ftp://ftp.tuwien.ac.at/pub/CPAN/modules/by-module/ \
	http://cpan.perl.org/CPAN/modules/by-module/

MASTER_SITE_R_CRAN+=    \
	http://cran.r-project.org/src/ \
	ftp://cran.r-project.org/pub/R/src/ \
	http://cran.at.r-project.org/src/ \
	ftp://cran.at.r-project.org/pub/R/src/ \
	http://cran.dk.r-project.org/src/ \
	http://cran.ch.r-project.org/src/ \
	http://cran.uk.r-project.org/src/ \
	http://cran.us.r-project.org/src/ \
	http://lib.stat.cmu.edu/R/CRAN/src/ \
	ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/ \
	http://stat.ethz.ch/CRAN/src/ \
	http://www.stats.bris.ac.uk/R/src/

MASTER_SITE_TEX_CTAN+= \
	ftp://ftp.funet.fi/pub/TeX/CTAN/ \
	ftp://ftp.tex.ac.uk/tex-archive/ \
	ftp://ftp.dante.de/tex-archive/

MASTER_SITE_SUNSITE+=   \
	ftp://sunsite.unc.edu/pub/Linux/ \
	ftp://ftp.chg.ru/pub/Linux/sunsite/ \
	ftp://ftp.kddlabs.co.jp/Linux/metalab.unc.edu/ \
	ftp://ftp.icm.edu.pl/pub/Linux/sunsite/ \
	ftp://ftp.nvg.ntnu.no/pub/mirrors/metalab.unc.edu/ \
	ftp://ftp.uvsq.fr/pub5/linux/sunsite/ \
	ftp://ftp.lip6.fr/pub/linux/sunsite/ \
	ftp://ftp.uni-stuttgart.de/pub/mirror/sunsite.unc.edu/pub/Linux/ \
	ftp://ftp.cs.tu-berlin.de/pub/linux/Mirrors/sunsite.unc.edu/ \
	ftp://sunsite.cnlab-switch.ch/mirror/linux/sunsite/ \
	ftp://ftp.tuwien.ac.at/pub/linux/ibiblio/

MASTER_SITE_GNOME+=     \
	ftp://ftp.gnome.org/pub/GNOME/ \
	ftp://ftp.sunet.se/pub/X11/GNOME/ \
	ftp://ftp.tuwien.ac.at/hci/GNOME/ \
	ftp://ftp.cse.buffalo.edu/pub/Gnome/ \
	ftp://ftp.dti.ad.jp/pub/X/gnome/ \
	ftp://ftp.kddlabs.co.jp/pub/GNOME/ \
	ftp://ftp.chg.ru/pub/X11/gnome/ \
	ftp://ftp.dataplus.se/pub/linux/gnome/ \
	ftp://ftp.dit.upm.es/linux/gnome/

MASTER_SITE_SOURCEFORGE+=	\
	http://belnet.dl.sourceforge.net/sourceforge/ \
	http://citkit.dl.sourceforge.net/sourceforge/ \
	http://easynews.dl.sourceforge.net/sourceforge/ \
	http://heanet.dl.sourceforge.net/sourceforge/ \
	http://internap.dl.sourceforge.net/sourceforge/ \
	http://keihanna.dl.sourceforge.net/sourceforge/ \
	http://kent.dl.sourceforge.net/sourceforge/ \
	http://mesh.dl.sourceforge.net/sourceforge/ \
	http://nchc.dl.sourceforge.net/sourceforge/ \
	http://optusnet.dl.sourceforge.net/sourceforge/ \
	http://ovh.dl.sourceforge.net/sourceforge/ \
	http://puzzle.dl.sourceforge.net/sourceforge/ \
	http://surfnet.dl.sourceforge.net/sourceforge/ \
	http://switch.dl.sourceforge.net/sourceforge/ \
	http://ufpr.dl.sourceforge.net/sourceforge/ \
	http://voxel.dl.sourceforge.net/sourceforge/
#	ftp://ftp2.sourceforge.net/pub/sourceforge/
#	ftp://ftp.tuwien.ac.at/linux/sourceforge/
#	http://sf.gds.tuwien.ac.at/

MASTER_SITE_SUSE+=	\
	ftp://rpmfind.net/linux/SuSE-Linux/${MACHINE_ARCH}/update/${SUSE_VERSION}/ \
	ftp://fr.rpmfind.net/linux/SuSE-Linux/${MACHINE_ARCH}/update/${SUSE_VERSION}/ \
	ftp://fr2.rpmfind.net/linux/SuSE-Linux/${MACHINE_ARCH}/update/${SUSE_VERSION}/ \
	ftp://ftp.duth.gr/pub/suse/suse/${MACHINE_ARCH}/${SUSE_VERSION}/suse/ \
	ftp://ftp.kddlabs.co.jp/Linux/packages/SuSE/suse/${MACHINE_ARCH}/${SUSE_VERSION}/suse/ \
	ftp://sunsite.cnlab-switch.ch/mirror/SuSE/suse/${MACHINE_ARCH}/${SUSE_VERSION}/suse/ \
	ftp://ftp.mirror.ac.uk/sites/ftp.suse.com/${MACHINE_ARCH}/${SUSE_VERSION}/suse/ \
	ftp://mirror.mcs.anl.gov/pub/ftp.suse.com/${MACHINE_ARCH}/${SUSE_VERSION}/suse/

MASTER_SITE_MOZILLA+=   \
	ftp://ftp.mozilla.org/pub/mozilla.org/mozilla/releases/ \
	ftp://ftp.fu-berlin.de/unix/network/www/mozilla/releases/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.mozilla.org/pub/mozilla/releases/ \
	ftp://ftp.funet.fi/pub/mirrors/ftp.mozilla.org/mozilla/releases/ \
	http://public.planetmirror.com.au/pub/mozilla/releases/ \
	ftp://ftp.rediris.es/mirror/mozilla/releases/ \
	ftp://ftp.chg.ru/pub/WWW/mozilla/mozilla/releases/

MASTER_SITE_XEMACS+=    \
	ftp://ftp.xemacs.org/pub/xemacs/ \
	ftp://ftp.dti.ad.jp/pub/unix/editor/xemacs/ \
	ftp://ftp.pasteur.fr/pub/computing/xemacs/ \
	http://public.planetmirror.com.au/pub/xemacs/ \
	ftp://mirror.aarnet.edu.au/pub/xemacs/ \
	ftp://mirror.cict.fr/xemacs/ \
	ftp://ftp.t.ring.gr.jp/pub/text/xemacs/ \
	ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/ \
	ftp://ftp.tu-darmstadt.de/pub/editors/xemacs/

MASTER_SITE_APACHE+=    \
	http://www.apache.org/dist/ \
	http://mirrors.ccs.neu.edu/Apache/dist/ \
	http://apache.planetmirror.com.au/dist/ \
	http://www.ibiblio.org/pub/mirrors/apache/ \
	http://apache.towardex.com/ \
	http://apache.oregonstate.edu/ \
	http://www.tux.org/pub/net/apache/dist/ \
	http://apache.secsup.org/dist/ \
	http://apache.osuosl.org/ \
	http://sunsite.tus.ac.jp/pub/apache/ \
	http://www.mirrorservice.org/sites/ftp.apache.org/ \
	http://ftp.plusline.de/ftp.apache.org/ \
	ftp://ftp.ccs.neu.edu/net/mirrors/Apache/dist/ \
	ftp://ftp.planetmirror.com.au/pub/apache/dist/ \
	ftp://ftp.tux.org/pub/net/apache/dist/ \
	ftp://www.ibiblio.org/pub/mirrors/apache/ \
	ftp://ftp.oregonstate.edu/pub/apache/ \
	ftp://apache.secsup.org/pub/apache/dist/ \
	ftp://sunsite.tus.ac.jp/pub/archives/www/apache/ \
	ftp://ftp.mirrorservice.org/sites/ftp.apache.org/ \
	ftp://ftp.plusline.de/pub/ftp.apache.org/

MASTER_SITE_DEBIAN+= \
	http://ftp.debian.org/debian/ \
	http://ftp.at.debian.org/debian/ \
	http://ftp.au.debian.org/debian/ \
	http://ftp.wa.au.debian.org/debian/ \
	http://ftp.bg.debian.org/debian/ \
	http://ftp.br.debian.org/debian/ \
	http://ftp.cl.debian.org/debian/ \
	http://ftp.cz.debian.org/debian/ \
	http://ftp.de.debian.org/debian/ \
	http://ftp2.de.debian.org/debian/ \
	http://ftp.ee.debian.org/debian/ \
	http://ftp.es.debian.org/debian/ \
	http://ftp.fi.debian.org/debian/ \
	http://ftp.fr.debian.org/debian/ \
	http://ftp2.fr.debian.org/debian/ \
	http://ftp.uk.debian.org/debian/ \
	http://ftp.hr.debian.org/debian/ \
	http://ftp.ie.debian.org/debian/ \
	http://ftp.is.debian.org/debian/ \
	http://ftp.it.debian.org/debian/ \
	http://ftp.jp.debian.org/debian/ \
	http://ftp.nl.debian.org/debian/ \
	http://ftp.no.debian.org/debian/ \
	http://ftp.nz.debian.org/debian/ \
	http://ftp.pl.debian.org/debian/ \
	http://ftp.ru.debian.org/debian/ \
	http://ftp.se.debian.org/debian/ \
	http://ftp.si.debian.org/debian/ \
	http://ftp.sk.debian.org/debian/ \
	http://ftp.tr.debian.org/debian/ \
	http://ftp.us.debian.org/debian/

MASTER_SITE_OPENOFFICE+=	\
	http://mirrors.isc.org/pub/openoffice/ \
	http://ftp.stardiv.de/pub/OpenOffice.org/ \
	http://openoffice.mirrors.ilisys.com.au/ \
	ftp://ftp.pucpr.br/openoffice/ \
	http://openoffice.behrsolutions.com/ \
	http://www.ibiblio.org/pub/mirrors/openoffice/ \
	ftp://ftp.ussg.iu.edu/pub/openoffice/ \
	http://openoffice.mirrors.pair.com/ftp/ \
	http://gd.tuwien.ac.at/office/openoffice/ \
	http://ftp.belnet.be/pub/mirror/ftp.openoffice.org/ \
	ftp://ftp.kulnet.kuleuven.ac.be/pub/mirror/openoffice.org/ \
	http://ftp.sh.cvut.cz/MIRRORS/OpenOffice/ \
	http://mirrors.sunsite.dk/openoffice/ \
	ftp://ftp.funet.fi/pub/mirrors/openoffice.org/ \
	ftp://openoffice.cict.fr/openoffice/ \
	http://ftp.club-internet.fr/pub/OpenOffice/ \
	ftp://sunsite.informatik.rwth-aachen.de/pub/mirror/OpenOffice/ \
	ftp://ftp.tu-chemnitz.de/pub/openoffice/ \
	ftp://ftp-stud.fht-esslingen.de/pub/Mirrors/ftp.openoffice.org/ \
	ftp://ftp.join.uni-muenster.de/pub/software/OpenOffice/ \
	http://ftp.leo.org/download/pub/comp/general/office/openoffice/ \
	ftp://openoffice.tu-bs.de/OpenOffice.org/ \
	http://ftp.ntua.gr/pub/OpenOffice/ \
	http://ftp.fsf.hu/OpenOffice.org/ \
	http://ftp.rhnet.is/pub/OpenOffice/ \
	http://na.mirror.garr.it/mirrors/openoffice/ \
	http://vlaai.snt.utwente.nl/pub/software/openoffice/ \
	http://niihau.student.utwente.nl/openoffice/ \
	http://borft.student.utwente.nl/openoffice/ \
	http://ftp.iasi.roedu.net/mirrors/openoffice.org/ \
	ftp://ftp.arnes.si/packages/OpenOffice.org/ \
	ftp://ftp.saix.net/pub/OpenOffice.org/ \
	http://ftp.rediris.es/ftp/mirror/openoffice.org/ \
	http://ftp.sunet.se/pub/Office/OpenOffice.org/ \
	ftp://mirror.switch.ch/mirror/OpenOffice/ \
	http://mirror.pacific.net.au/openoffice/ \
	http://public.planetmirror.com.au/pub/openoffice/ \
	http://komo.vlsm.org/openoffice/ \
	ftp://ftp.kddlabs.co.jp/office/openoffice/ \
	ftp://ftp.t.ring.gr.jp/pub/misc/openoffice/ \
	http://mymirror.asiaosc.org/openoffice/ \
	ftp://ftp.kr.freebsd.org/pub/openoffice/ \
	http://www.fs.tum.de/~mrauch/OpenOffice/download/

MASTER_SITE_CYGWIN+= \
	http://mirrors.kernel.org/sources.redhat.com/cygwin/ \
	http://mirrors.rcn.net/pub/sourceware/cygwin/ \
	http://mirrors.xmission.com/cygwin/ \
	ftp://ftp.t.ring.gr.jp/pub/pc/gnu-win32/ \
	ftp://ftp.funet.fi/pub/mirrors/cygwin.com/pub/cygwin/

MASTER_SITE_IFARCHIVE+= \
	http://ifarchive.flavorplex.com/if-archive/ \
	http://ifarchive.heanet.ie/if-archive/ \
	http://ifarchive.giga.or.at/if-archive/

MASTER_SITE_FREEBSD+= \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/distfiles/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/distfiles/

MASTER_SITE_FREEBSD_LOCAL+= \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/ \
	ftp://ftp.jp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/

# The primary backup site.
MASTER_SITE_BACKUP?=	\
	http://ftp.fi.NetBSD.org/pub/NetBSD/packages/distfiles/ \
	ftp://ftp.NetBSD.org/pub/NetBSD/packages/distfiles/ \
	ftp://ftp.FreeBSD.org/pub/FreeBSD/distfiles/

.endif # BSD_SITES_MK
