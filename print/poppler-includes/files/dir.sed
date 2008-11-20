1,/if ENABLE_XPDF_HEADERS/ d
/endif/,$ d
s,^[a-z_]*_includedir = ..includedir./,,p
