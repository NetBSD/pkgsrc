1,/if(ENABLE_XPDF_HEADERS)/ d
/^endif/,$ d
s/^  *\([a-z]*\/[A-Za-z0-9_-]*\.h\).*/\1/p
