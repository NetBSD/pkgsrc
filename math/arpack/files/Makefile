BLAS  = isamax.lo sasum.lo saxpy.lo scopy.lo sdot.lo  snrm2.lo srot.lo  srotg.lo \
        sscal.lo  sswap.lo sgemv.lo sger.lo  ssymv.lo ssyr2.lo strmm.lo sgbmv.lo \
        idamax.lo dasum.lo daxpy.lo dcopy.lo ddot.lo  dnrm2.lo drot.lo  drotg.lo \
        dscal.lo  dswap.lo dgemv.lo dger.lo  dsymv.lo dsyr2.lo dtrmm.lo dgbmv.lo \
        icamax.lo caxpy.lo ccopy.lo cdotc.lo cdotu.lo cgbmv.lo  cgemv.lo cgerc.lo \
        cgeru.lo  cscal.lo csscal.lo cswap.lo ctrmm.lo ctrsv.lo scasum.lo scnrm2.lo \
        izamax.lo zaxpy.lo zcopy.lo zdotc.lo zdotu.lo zgbmv.lo  zgemv.lo zgerc.lo \
        zgeru.lo zscal.lo zdscal.lo zswap.lo ztrmm.lo ztrsv.lo dzasum.lo dznrm2.lo

LAPACK= sgeqr2.lo slabad.lo slacon.lo slacpy.lo sladiv.lo slae2.lo slaev2.lo \
        slaexc.lo slagtm.lo slahqr.lo slaln2.lo slamch.lo slange.lo slanhs.lo \
        slanst.lo slanv2.lo slaptm.lo slapy2.lo slapy3.lo slaran.lo slarf.lo \
        slarfg.lo slarfx.lo slarnd.lo slarnv.lo slartg.lo slaruv.lo slascl.lo \
        slaset.lo slasr.lo  slasrt.lo slassq.lo slasy2.lo sorm2r.lo ssteqr.lo \
        strevc.lo strexc.lo strsen.lo strsyl.lo \
        dgeqr2.lo dlabad.lo dlacon.lo dlacpy.lo dladiv.lo dlae2.lo dlaev2.lo \
        dlaexc.lo dlagtm.lo dlahqr.lo dlaln2.lo dlamch.lo dlange.lo dlanhs.lo \
        dlanst.lo dlanv2.lo dlaptm.lo dlapy2.lo dlapy3.lo dlaran.lo dlarf.lo \
        dlarfg.lo dlarfx.lo dlarnd.lo dlarnv.lo dlartg.lo dlaruv.lo dlascl.lo \
        dlaset.lo dlasr.lo  dlasrt.lo dlassq.lo dlasy2.lo dorm2r.lo dsteqr.lo \
        dtrevc.lo dtrexc.lo dtrsen.lo dtrsyl.lo \
        ilaenv.lo lsame.lo lsamen.lo xerbla.lo xlaenv.lo \
        icmax1.lo \
        izmax1.lo \
        cgeqr2.lo clacon.lo clacpy.lo cladiv.lo clahqr.lo clange.lo clanhs.lo \
        clarf.lo  clarfg.lo clarnv.lo clartg.lo clascl.lo claset.lo classq.lo \
        clatrs.lo cmach.lo  crot.lo   ctrevc.lo ctrexc.lo ctrsen.lo ctrsyl.lo \
        cunm2r.lo \
        scsum1.lo \
        zgeqr2.lo zlacon.lo zlacpy.lo zladiv.lo zlahqr.lo zlange.lo zlanhs.lo \
        zlarf.lo  zlarfg.lo zlarnv.lo zlartg.lo zlascl.lo zlaset.lo zlassq.lo \
        zlatrs.lo zmach.lo  zrot.lo   ztrevc.lo ztrexc.lo ztrsen.lo ztrsyl.lo \
        zunm2r.lo \
        dzsum1.lo

ARPACK= sgetv0.lo slaqrb.lo sstqrb.lo ssortc.lo ssortr.lo sstatn.lo sstats.lo \
        snaitr.lo snapps.lo snaup2.lo snaupd.lo snconv.lo sneigh.lo sngets.lo \
        ssaitr.lo ssapps.lo ssaup2.lo ssaupd.lo ssconv.lo sseigt.lo ssgets.lo \
        sneupd.lo sseupd.lo ssesrt.lo \
        dgetv0.lo dlaqrb.lo dstqrb.lo dsortc.lo dsortr.lo dstatn.lo dstats.lo \
        dnaitr.lo dnapps.lo dnaup2.lo dnaupd.lo dnconv.lo dneigh.lo dngets.lo \
        dsaitr.lo dsapps.lo dsaup2.lo dsaupd.lo dsconv.lo dseigt.lo dsgets.lo \
        dneupd.lo dseupd.lo dsesrt.lo \
        cnaitr.lo cnapps.lo cnaup2.lo cnaupd.lo cneigh.lo cneupd.lo cngets.lo \
        cgetv0.lo csortc.lo cstatn.lo \
        znaitr.lo znapps.lo znaup2.lo znaupd.lo zneigh.lo zneupd.lo zngets.lo \
        zgetv0.lo zsortc.lo zstatn.lo

.SUFFIXES:	.f	.lo

.PATH: BLAS LAPACK SRC

.f.lo:
	libtool --mode=compile ${FC} -o $@ -c ${FFLAGS} $<

all: libarpack.la

libarpack.la: ${BLAS} ${LAPACK} ${ARPACK}
	libtool --mode=link ${FC} -o libarpack.la ${BLAS} ${LAPACK} ${ARPACK} -version-info 1 -rpath ${PREFIX}/lib
